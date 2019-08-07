// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import com.google.common.collect.ImmutableSet;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;
import java.util.Arrays;

class OFBsnLuaUploadVer13 implements OFBsnLuaUpload {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnLuaUploadVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int MINIMUM_LENGTH = 82;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static long DEFAULT_XID = 0x0L;
        private final static Set<OFBsnLuaUploadFlags> DEFAULT_FLAGS = ImmutableSet.<OFBsnLuaUploadFlags>of();
        private final static String DEFAULT_FILENAME = "";
        private final static byte[] DEFAULT_DATA = new byte[0];

    // OF message fields
    private final long xid;
    private final Set<OFBsnLuaUploadFlags> flags;
    private final String filename;
    private final byte[] data;
//
    // Immutable default instance
    final static OFBsnLuaUploadVer13 DEFAULT = new OFBsnLuaUploadVer13(
        DEFAULT_XID, DEFAULT_FLAGS, DEFAULT_FILENAME, DEFAULT_DATA
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnLuaUploadVer13(long xid, Set<OFBsnLuaUploadFlags> flags, String filename, byte[] data) {
        if(flags == null) {
            throw new NullPointerException("OFBsnLuaUploadVer13: property flags cannot be null");
        }
        if(filename == null) {
            throw new NullPointerException("OFBsnLuaUploadVer13: property filename cannot be null");
        }
        if(data == null) {
            throw new NullPointerException("OFBsnLuaUploadVer13: property data cannot be null");
        }
        this.xid = U32.normalize(xid);
        this.flags = flags;
        this.filename = filename;
        this.data = data;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

    @Override
    public OFType getType() {
        return OFType.EXPERIMENTER;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x40L;
    }

    @Override
    public Set<OFBsnLuaUploadFlags> getFlags() {
        return flags;
    }

    @Override
    public String getFilename() {
        return filename;
    }

    @Override
    public byte[] getData() {
        return data;
    }



    public OFBsnLuaUpload.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnLuaUpload.Builder {
        final OFBsnLuaUploadVer13 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean flagsSet;
        private Set<OFBsnLuaUploadFlags> flags;
        private boolean filenameSet;
        private String filename;
        private boolean dataSet;
        private byte[] data;

        BuilderWithParent(OFBsnLuaUploadVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

    @Override
    public OFType getType() {
        return OFType.EXPERIMENTER;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBsnLuaUpload.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x40L;
    }

    @Override
    public Set<OFBsnLuaUploadFlags> getFlags() {
        return flags;
    }

    @Override
    public OFBsnLuaUpload.Builder setFlags(Set<OFBsnLuaUploadFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public String getFilename() {
        return filename;
    }

    @Override
    public OFBsnLuaUpload.Builder setFilename(String filename) {
        this.filename = filename;
        this.filenameSet = true;
        return this;
    }
    @Override
    public byte[] getData() {
        return data;
    }

    @Override
    public OFBsnLuaUpload.Builder setData(byte[] data) {
        this.data = data;
        this.dataSet = true;
        return this;
    }


        @Override
        public OFBsnLuaUpload build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                Set<OFBsnLuaUploadFlags> flags = this.flagsSet ? this.flags : parentMessage.flags;
                if(flags == null)
                    throw new NullPointerException("Property flags must not be null");
                String filename = this.filenameSet ? this.filename : parentMessage.filename;
                if(filename == null)
                    throw new NullPointerException("Property filename must not be null");
                byte[] data = this.dataSet ? this.data : parentMessage.data;
                if(data == null)
                    throw new NullPointerException("Property data must not be null");

                //
                return new OFBsnLuaUploadVer13(
                    xid,
                    flags,
                    filename,
                    data
                );
        }

    }

    static class Builder implements OFBsnLuaUpload.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean flagsSet;
        private Set<OFBsnLuaUploadFlags> flags;
        private boolean filenameSet;
        private String filename;
        private boolean dataSet;
        private byte[] data;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

    @Override
    public OFType getType() {
        return OFType.EXPERIMENTER;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBsnLuaUpload.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x40L;
    }

    @Override
    public Set<OFBsnLuaUploadFlags> getFlags() {
        return flags;
    }

    @Override
    public OFBsnLuaUpload.Builder setFlags(Set<OFBsnLuaUploadFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public String getFilename() {
        return filename;
    }

    @Override
    public OFBsnLuaUpload.Builder setFilename(String filename) {
        this.filename = filename;
        this.filenameSet = true;
        return this;
    }
    @Override
    public byte[] getData() {
        return data;
    }

    @Override
    public OFBsnLuaUpload.Builder setData(byte[] data) {
        this.data = data;
        this.dataSet = true;
        return this;
    }
//
        @Override
        public OFBsnLuaUpload build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            Set<OFBsnLuaUploadFlags> flags = this.flagsSet ? this.flags : DEFAULT_FLAGS;
            if(flags == null)
                throw new NullPointerException("Property flags must not be null");
            String filename = this.filenameSet ? this.filename : DEFAULT_FILENAME;
            if(filename == null)
                throw new NullPointerException("Property filename must not be null");
            byte[] data = this.dataSet ? this.data : DEFAULT_DATA;
            if(data == null)
                throw new NullPointerException("Property data must not be null");


            return new OFBsnLuaUploadVer13(
                    xid,
                    flags,
                    filename,
                    data
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnLuaUpload> {
        @Override
        public OFBsnLuaUpload readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 4
            byte version = bb.readByte();
            if(version != (byte) 0x4)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_13(4), got="+version);
            // fixed value property type == 4
            byte type = bb.readByte();
            if(type != (byte) 0x4)
                throw new OFParseError("Wrong type: Expected=OFType.EXPERIMENTER(4), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long xid = U32.f(bb.readInt());
            // fixed value property experimenter == 0x5c16c7L
            int experimenter = bb.readInt();
            if(experimenter != 0x5c16c7)
                throw new OFParseError("Wrong experimenter: Expected=0x5c16c7L(0x5c16c7L), got="+experimenter);
            // fixed value property subtype == 0x40L
            int subtype = bb.readInt();
            if(subtype != 0x40)
                throw new OFParseError("Wrong subtype: Expected=0x40L(0x40L), got="+subtype);
            Set<OFBsnLuaUploadFlags> flags = OFBsnLuaUploadFlagsSerializerVer13.readFrom(bb);
            String filename = ChannelUtils.readFixedLengthString(bb, 64);
            byte[] data = ChannelUtils.readBytes(bb, length - (bb.readerIndex() - start));

            OFBsnLuaUploadVer13 bsnLuaUploadVer13 = new OFBsnLuaUploadVer13(
                    xid,
                      flags,
                      filename,
                      data
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnLuaUploadVer13);
            return bsnLuaUploadVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnLuaUploadVer13Funnel FUNNEL = new OFBsnLuaUploadVer13Funnel();
    static class OFBsnLuaUploadVer13Funnel implements Funnel<OFBsnLuaUploadVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnLuaUploadVer13 message, PrimitiveSink sink) {
            // fixed value property version = 4
            sink.putByte((byte) 0x4);
            // fixed value property type = 4
            sink.putByte((byte) 0x4);
            // FIXME: skip funnel of length
            sink.putLong(message.xid);
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property subtype = 0x40L
            sink.putInt(0x40);
            OFBsnLuaUploadFlagsSerializerVer13.putTo(message.flags, sink);
            sink.putUnencodedChars(message.filename);
            sink.putBytes(message.data);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnLuaUploadVer13> {
        @Override
        public void write(ByteBuf bb, OFBsnLuaUploadVer13 message) {
            int startIndex = bb.writerIndex();
            // fixed value property version = 4
            bb.writeByte((byte) 0x4);
            // fixed value property type = 4
            bb.writeByte((byte) 0x4);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeInt(U32.t(message.xid));
            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property subtype = 0x40L
            bb.writeInt(0x40);
            OFBsnLuaUploadFlagsSerializerVer13.writeTo(bb, message.flags);
            ChannelUtils.writeFixedLengthString(bb, message.filename, 64);
            bb.writeBytes(message.data);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFBsnLuaUploadVer13: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnLuaUploadVer13(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("flags=").append(flags);
        b.append(", ");
        b.append("filename=").append(filename);
        b.append(", ");
        b.append("data=").append(Arrays.toString(data));
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFBsnLuaUploadVer13 other = (OFBsnLuaUploadVer13) obj;

        if( xid != other.xid)
            return false;
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (filename == null) {
            if (other.filename != null)
                return false;
        } else if (!filename.equals(other.filename))
            return false;
        if (!Arrays.equals(data, other.data))
                return false;
        return true;
    }

    @Override
    public boolean equalsIgnoreXid(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFBsnLuaUploadVer13 other = (OFBsnLuaUploadVer13) obj;

        // ignore XID
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (filename == null) {
            if (other.filename != null)
                return false;
        } else if (!filename.equals(other.filename))
            return false;
        if (!Arrays.equals(data, other.data))
                return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((filename == null) ? 0 : filename.hashCode());
        result = prime * result + Arrays.hashCode(data);
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((filename == null) ? 0 : filename.hashCode());
        result = prime * result + Arrays.hashCode(data);
        return result;
    }

}
